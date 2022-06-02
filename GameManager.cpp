#include "GameManager.h"

int GameManager::getCurrent_player() { return current_player; }

void GameManager::read()
{
    ifstream cmd;
    cmd.open("command.txt");

    if (!cmd.is_open())
    {
        cout << "[ERROR] cannot open the file to be read.\n";
        return;
    }

    position fromPos;
    position toPos;

    Viewer viewer(board);
    board.initializeBoard();

    while (!cmd.eof())
    {
        cout << "\n";
        //board.Print();
        viewer.printBoard(board);
        cout << "\n";

        string sub; // sub command: a line of the file
        getline(cmd, sub);
        string player = sub.substr(8, sub.find(","));
        // find "n" in "Action"
        string actor = sub.substr(sub.find("n") + 3, 2);
        //actor.erase(actor.find(" "));
        string action = sub.substr(sub.find("("));

        fromPos.x = action[1] - '0';
        fromPos.y = action[4] - '0';
        toPos.x = action[11] - '0';
        toPos.y = action[14] - '0';

        /*
        stringstream ssPos;
        ssPos << action;
        int temp;
        // vector to store initial & destined position
        // Priority: x1->y1->x2->y2
        vector <int> pos;
        while (ssPos >> temp)
            pos.push_back(temp);
        cout << temp;
        */

        //========================================
        // fetch the data to the right type
        int plyr = stoi(player);
        current_player = plyr;

        if (getCurrent_player() == 1) // red
        {
            cout << "\n\n********* red turns *********\n\n";

            cout << "moving from (in form x y) : ";
            cout << fromPos.x << " " << fromPos.y << "\n";
            cout << "moving to a destination (in form x y) : ";
            cout << toPos.x << " " << toPos.y << "\n";

            string c = board.find(fromPos.x, fromPos.y);

            if (c[0] != actor[0] && c[1] != actor[1]) {
                cout << "[ERROR] giving the wrong command\n\n";
                continue;
            }
            else {
                cout << "the moving chess is : " << c << "\n\n";
            }

            switch (actor[0])
            {
            case 'G': // General
            {
                General chess(board, current_player);
                chess.Move(board, fromPos, toPos);
                break;
            }
            case 'A': // Advisor
            {
                Advisor chess(board, current_player);
                chess.Move(board, fromPos, toPos);
                break;
            }
            case 'E': // Elephant
            {
                Elephant chess(board, current_player);
                chess.Move(board, fromPos, toPos);
                break;
            }
            case 'C': // Chariot / Cannon
                if (actor[1] == 'h') // Chariot
                {
                    Chariot chess(board, current_player);
                    chess.Move(board, fromPos, toPos);
                }
                else // Cannon
                {
                    Cannon chess(board, current_player);
                    chess.Move(board, fromPos, toPos);
                }
                break;
            case 'H': // Horse
            {
                Horse chess(board, current_player);
                chess.Move(board, fromPos, toPos);
                break;
            }
            case 'S': // Soldier
            {
                Soldier chess(board, current_player);
                chess.Move(board, fromPos, toPos);
                break;
            }
            default:
                break;
            }

            if (board.whetherCheck(current_player)) {
                cout << "[NOTICE] check! checkmate!\n";
            }
            else {
                // 判斷是否為欠行 是就印[NOTICE] stalemate!
                if (board.whetherStalemate(current_player)) {
                    cout << "[NOTICE] stalemate!\n";
                }
            }

        }
        else //black
        {
            current_player = 0;
            cout << "\n\n******** black turns ********\n\n";

            cout << "moving from (in form x y) : ";
            cout << fromPos.x << " " << fromPos.y << "\n";
            cout << "moving to a destination (in form x y) : ";
            cout << toPos.x << " " << toPos.y << "\n";

            string c = board.find(fromPos.x, fromPos.y);

            if (c[0] != actor[0] && c[1] != actor[1]) {
                cout << "[ERROR] giving the wrong command\n\n";
                continue;
            }
            else {
                cout << "the moving chess is : " << c << "\n\n";
            }

            switch (actor[0])
            {
            case 'G': // General
            {
                General chess(board, current_player);
                chess.Move(board, fromPos, toPos);
                break;
            }
            case 'A': // Advisor
            {
                Advisor chess(board, current_player);
                chess.Move(board, fromPos, toPos);
                break;
            }
            case 'E': // Elephant
            {
                Elephant chess(board, current_player);
                chess.Move(board, fromPos, toPos);
                break;
            }
            case 'C': // Chariot / Cannon
                if (actor[1] == 'h') // Chariot
                {
                    Chariot chess(board, current_player);
                    chess.Move(board, fromPos, toPos);
                }
                else // Cannon
                {
                    Cannon chess(board, current_player);
                    chess.Move(board, fromPos, toPos);
                }
                break;
            case 'H': // Horse
            {
                Horse chess(board, current_player);
                chess.Move(board, fromPos, toPos);
                break;
            }
            case 'S': // Soldier
            {
                Soldier chess(board, current_player);
                chess.Move(board, fromPos, toPos);
                break;
            }
            default:
                break;
            }

            if (board.whetherCheck(current_player)) {
                cout << "[NOTICE] check! checkmate!\n";
            }
            else {
                // 判斷是否為欠行 是就印[NOTICE] stalemate!
                if (board.whetherStalemate(current_player)) {
                    cout << "[NOTICE] stalemate!\n";
                }
            }

        }
        viewer.printBoard(board);

        if (current_player == 2 && !board.findGeneral(1)) {
            cout << "\n========= black win =========\n";
            //board.initializeBoard();
        }
        else if (current_player == 1 && !board.findGeneral(0)) {
            cout << "\n========== red win ==========\n";
            //board.initializeBoard();
        }
        //cout << "\n==========  將 死  ==========\n";
    }

    cmd.close();
}

void GameManager::play()
{
    wFile.open("now.txt");
    if (!wFile.is_open())
    {
        cout << "[ERROR] cannot open the file to be written.\n";
        return;
    }

    current_player = 1;     // 紅方先走
    //初始化盤面
    Viewer viewer(board);
    string giveUp = "";
    board.initializeBoard();

    //確認是否結束 -> 將死 欠行
    while (1/*check_end(board)*/)
    {
        cout << "\n";
        //board.Print();
        viewer.printBoard(board);
        cout << "\ncin continue to keep going ; cin giveup to end the game : ";
        cin >> giveUp;
        if (giveUp == "giveup") {
            if (current_player != 0) {
                cout << "\n========= black win =========\n";
            }
            else {
                cout << "\n========== red win ==========\n";
            }
            break;
        }
        chooseChess(current_player);

        //換對方走 同時確認是否結束遊戲(將死 欠行)
        if (current_player == 0 && board.findGeneral(1)) {

            if (board.whetherCheck(current_player)) {
                cout << "\n[NOTICE] check! checkmate!\n";
            }
            else {
                // 判斷是否為欠行 是就印[NOTICE] stalemate!
                if (board.whetherStalemate(current_player)) {
                    cout << "\n[NOTICE] stalemate!\n";
                }
            }

            current_player = 1;
        }
        else if (current_player == 1 && board.findGeneral(0)) {

            if (board.whetherCheck(current_player)) {
                cout << "\n[NOTICE] check! checkmate!\n";
            }
            else {
                // 判斷是否為欠行 是就印[NOTICE] stalemate!
                if (board.whetherStalemate(current_player)) {
                    cout << "\n[NOTICE] stalemate!\n";
                }
            }

            current_player = 0;
        }
        else {
            //board.Print();
            viewer.printBoard(board);
            if (current_player == 0 && !board.findGeneral(1)) {
                cout << "\n========= black win =========\n";
            }
            else if (current_player == 1 && !board.findGeneral(0)) {
                cout << "\n========== red win ==========\n";
            }
            //cout << "\n==========  將 死  ==========\n";
            break;
        }

    }
}

void GameManager::chooseChess(int current_player)
{
    position fromPos;
    position toPos;

    if (current_player == 1) {
        cout << "\n\n********* red turns *********\n\n";
    }
    else {
        cout << "\n\n******** black turns ********\n\n";
    }
    cout << "choose a chess (in form x y) : ";
    cin >> fromPos.x >> fromPos.y;
    //cout << "choose a destination (in form x y) : ";
    //cin >> toPos.x >> toPos.y;

    string c = board.find(fromPos.x, fromPos.y);
    if (c != "Error") {
        cout << "the moving chess is : " << c << "\n\n";
    }
    else {
        cout << "[ERROR] giving the wrong command\n\n";
    }

    int count = 0;
    if (c == "General") {
        General chess(board, current_player);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                toPos.x = j;
                toPos.y = i;
                if (count == 0 && chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) == "Error") {
                    count++;
                    cout << "destination that can be chosen : / " << j << " " << i << " / ";
                }
                else if (chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) == "Error") {
                    cout << j << " " << i << " / ";
                }
            }
        }
        cout << "\n";
        count = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                toPos.x = j;
                toPos.y = i;
                if (count == 0 && chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) != "Error") {
                    count++;
                    cout << "chess that can be eaten : / " << j << " " << i << " / ";
                }
                else if (chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) != "Error") {
                    cout << j << " " << i << " / ";
                }
            }
        }
        cout << "\n\nchoose a destination (in form x y) : ";
        cin >> toPos.x >> toPos.y;
        chess.Move(board, fromPos, toPos);
    }
    else if (c == "Advisor") {
        Advisor chess(board, current_player);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                toPos.x = j;
                toPos.y = i;
                if (count == 0 && chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) == "Error") {
                    count++;
                    cout << "destination that can be chosen : / " << j << " " << i << " / ";
                }
                else if (chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) == "Error") {
                    cout << j << " " << i << " / ";
                }
            }
        }
        cout << "\n";
        count = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                toPos.x = j;
                toPos.y = i;
                if (count == 0 && chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) != "Error") {
                    count++;
                    cout << "chess that can be eaten : / " << j << " " << i << " / ";
                }
                else if (chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) != "Error") {
                    cout << j << " " << i << " / ";
                }
            }
        }
        cout << "\n\nchoose a destination (in form x y) : ";
        cin >> toPos.x >> toPos.y;
        chess.Move(board, fromPos, toPos);
    }
    else if (c == "Elephant") {
        Elephant chess(board, current_player);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                toPos.x = j;
                toPos.y = i;
                if (count == 0 && chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) == "Error") {
                    count++;
                    cout << "destination that can be chosen : / " << j << " " << i << " / ";
                }
                else if (chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) == "Error") {
                    cout << j << " " << i << " / ";
                }
            }
        }
        cout << "\n";
        count = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                toPos.x = j;
                toPos.y = i;
                if (count == 0 && chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) != "Error") {
                    count++;
                    cout << "chess that can be eaten : / " << j << " " << i << " / ";
                }
                else if (chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) != "Error") {
                    cout << j << " " << i << " / ";
                }
            }
        }
        cout << "\n\nchoose a destination (in form x y) : ";
        cin >> toPos.x >> toPos.y;
        chess.Move(board, fromPos, toPos);
    }
    else if (c == "Chariot") {
        Chariot chess(board, current_player);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                toPos.x = j;
                toPos.y = i;
                if (count == 0 && chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) == "Error") {
                    count++;
                    cout << "destination that can be chosen : / " << j << " " << i << " / ";
                }
                else if (chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) == "Error") {
                    cout << j << " " << i << " / ";
                }
            }
        }
        cout << "\n";
        count = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                toPos.x = j;
                toPos.y = i;
                if (count == 0 && chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) != "Error") {
                    count++;
                    cout << "chess that can be eaten : / " << j << " " << i << " / ";
                }
                else if (chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) != "Error") {
                    cout << j << " " << i << " / ";
                }
            }
        }
        cout << "\n\nchoose a destination (in form x y) : ";
        cin >> toPos.x >> toPos.y;
        chess.Move(board, fromPos, toPos);
    }
    else if (c == "Horse") {
        Horse chess(board, current_player);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                toPos.x = j;
                toPos.y = i;
                if (count == 0 && chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) == "Error") {
                    count++;
                    cout << "destination that can be chosen : / " << j << " " << i << " / ";
                }
                else if (chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) == "Error") {
                    cout << j << " " << i << " / ";
                }
            }
        }
        cout << "\n";
        count = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                toPos.x = j;
                toPos.y = i;
                if (count == 0 && chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) != "Error") {
                    count++;
                    cout << "chess that can be eaten : / " << j << " " << i << " / ";
                }
                else if (chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) != "Error") {
                    cout << j << " " << i << " / ";
                }
            }
        }
        cout << "\n\nchoose a destination (in form x y) : ";
        cin >> toPos.x >> toPos.y;
        chess.Move(board, fromPos, toPos);
    }
    else if (c == "Cannon") {
        Cannon chess(board, current_player);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                toPos.x = j;
                toPos.y = i;
                if (count == 0 && chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) == "Error") {
                    count++;
                    cout << "destination that can be chosen : / " << j << " " << i << " / ";
                }
                else if (chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) == "Error") {
                    cout << j << " " << i << " / ";
                }
            }
        }
        cout << "\n";
        count = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                toPos.x = j;
                toPos.y = i;
                if (count == 0 && chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) != "Error") {
                    count++;
                    cout << "chess that can be eaten : / " << j << " " << i << " / ";
                }
                else if (chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) != "Error") {
                    cout << j << " " << i << " / ";
                }
            }
        }
        cout << "\n\nchoose a destination (in form x y) : ";
        cin >> toPos.x >> toPos.y;
        chess.Move(board, fromPos, toPos);
    }
    else if (c == "Soldier") {
        Soldier chess(board, current_player);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                toPos.x = j;
                toPos.y = i;
                if (count == 0 && chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) == "Error") {
                    count++;
                    cout << "destination that can be chosen : / " << j << " " << i << " / ";
                }
                else if (chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) == "Error") {
                    cout << j << " " << i << " / ";
                }
            }
        }
        cout << "\n";
        count = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                toPos.x = j;
                toPos.y = i;
                if (count == 0 && chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) != "Error") {
                    count++;
                    cout << "chess that can be eaten : / " << j << " " << i << " / ";
                }
                else if (chess.eatable(board, fromPos, toPos) && board.find(toPos.x, toPos.y) != "Error") {
                    cout << j << " " << i << " / ";
                }
            }
        }
        cout << "\n\nchoose a destination (in form x y) : ";
        cin >> toPos.x >> toPos.y;
        chess.Move(board, fromPos, toPos);
    }

    //player[current_player].setType(c);

    //player[current_player].Move(board, fromPos, toPos);

}