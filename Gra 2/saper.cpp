void show_board()
{
    system("cls");

    for (int i = 0; i<10; i++)
    {
        for (int j = 0; j<10; j++)
        {
            if (j==pos_x && i==pos_y)
            {
                SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE  ), 0x02);
                cout << "#";
            }
            else
            {
                SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE  ), 0x07);
                if (board[j][i].revealed==true)
                {
                    if (board[j][i].value==0)
                        cout << " ";
                    else
                        cout << board[j][i].value;

                }
                if (board[j][i].revealed==false)
                    cout << "#";
            }
        }
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
        cout << endl;
    }

    cout << "\nCursor Position:\n";
    cout << "X: " << pos_x << endl;
    cout << "Y: " << pos_y << endl;
}


bool set_mine (int pos_x, int pos_y)
{
    if (board[pos_x][pos_y].value!=9)
    {
        board[pos_x][pos_y].value = 9;
        for (int k = -1; k<2; k++)
            for (int l = -1; l<2; l++)
            {
                if ((pos_x+l)<0 || (pos_y+k)<0 ) continue;
                if ((pos_x+l)>9 || (pos_y+k)>9 ) continue;

                if (board[pos_x+l][pos_y+k].value==9) continue;
                board[pos_x+l][pos_y+k].value += 1;
            }
    }

    return true;
}


void reveal_board(int x, int y)
{
    if (x<0 || x>9) return;
    if (y<0 || y>9) return;
    if (board[x][y].revealed==true) return;
    if(board[x][y].value!=9 && board[x][y].revealed==false)
        board[x][y].revealed=true;

    if (board[x][y].value!=0) return;
    reveal_board(x-1,y-1);
    reveal_board(x-1,y);
    reveal_board(x-1,y+1);
    reveal_board(x+1,y-1);
    reveal_board(x+1,y);
    reveal_board(x+1,y+1);
    reveal_board(x,y-1);
    reveal_board(x,y);
    reveal_board(x,y+1);
}

void control()
{
    if ((GetKeyState(enter) & 0x8000))
    {
        if (board[pos_x][pos_y].value==9)
            end = 2;

        reveal_board(pos_x, pos_y);
        show_board();
    }
    if ((GetKeyState(arrow_right) & 0x8000) && pos_x<9) pos_x++;
    if ((GetKeyState(arrow_left) & 0x8000) && pos_x>0) pos_x--;
    if ((GetKeyState(arrow_down) & 0x8000) && pos_y<9) pos_y++;
    if ((GetKeyState(arrow_up) & 0x8000) && pos_y>0) pos_y--;
    if (o_pos_y==pos_y && o_pos_x==pos_x) return;
    o_pos_y = pos_y;
    o_pos_x = pos_x;
    show_board();
}

int main()
{
    generate_board();
    random_position();
    Sleep(250);
    while(end==0)
    {
        Sleep(50);
        control();
        if (win_condition()==true) end = 1;
    }
    if (end==1) cout << "\nCongratulations You Won";
    if (end==2) cout << "\nTry Again";
    system ("pause >nul");
    return 0;
}

