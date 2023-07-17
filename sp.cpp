#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 100;

// Ham kiem tra o co hop le trong ma tran hay khong
bool isValidCell(int x, int y, int rows, int cols) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

// Ham di chuyen robot
void moveRobot(int grid[MAX_SIZE][MAX_SIZE], int x, int y, int& score, int path[], int& pathSize) {
    score += grid[x][y];
    path[pathSize++] = grid[x][y];
    grid[x][y] = 0;

    int maxValue = 0;
    int nextX = -1, nextY = -1;

    // Kiem tra o phia tren
    if (isValidCell(x - 1, y, MAX_SIZE, MAX_SIZE) && grid[x - 1][y] > maxValue) {
        maxValue = grid[x - 1][y];
        nextX = x - 1;
        nextY = y;
    }

    // Kiem tra o phia duoi
    if (isValidCell(x + 1, y, MAX_SIZE, MAX_SIZE) && grid[x + 1][y] > maxValue) {
        maxValue = grid[x + 1][y];
        nextX = x + 1;
        nextY = y;
    }

    // Kiem tra o phia trai
    if (isValidCell(x, y - 1, MAX_SIZE, MAX_SIZE) && grid[x][y - 1] > maxValue) {
        maxValue = grid[x][y - 1];
        nextX = x;
        nextY = y - 1;
    }

    // Kiem tra o phia phai
    if (isValidCell(x, y + 1, MAX_SIZE, MAX_SIZE) && grid[x][y + 1] > maxValue) {
        maxValue = grid[x][y + 1];
        nextX = x;
        nextY = y + 1;
    }

    // Neu tim thay o co gia tri lon nhat, di chuyen robot den o do
    if (nextX != -1 && nextY != -1) {
        moveRobot(grid, nextX, nextY, score, path, pathSize);
    }
}

// Ham tim diem giao nhau giua 2 robot
void findIntersection(int grid[MAX_SIZE][MAX_SIZE], int x1, int y1, int x2, int y2) {
    int grid1[MAX_SIZE][MAX_SIZE];
    int grid2[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            grid1[i][j] = grid[i][j];
            grid2[i][j] = grid[i][j];
        }
    }
    int score1 = 0;
    int path1[MAX_SIZE * MAX_SIZE];
    int pathSize1 = 0;
    moveRobot(grid1, x1, y1, score1, path1, pathSize1);

    int score2 = 0;
    int path2[MAX_SIZE * MAX_SIZE];
    int pathSize2 = 0;
    moveRobot(grid2, x2, y2, score2, path2, pathSize2);

    cout << "Duong di cua Robot 1: ";
    for (int i = 0; i < pathSize1; i++) {
        cout << path1[i] << " ";
    }
    cout << endl;

    cout << "Duong di cua Robot 2: ";
    for (int i = 0; i < pathSize2; i++) {
        cout << path2[i] << " ";
    }
    cout << endl;

    cout << "Cac vi tri trung nhau cua Robot 1 va Robot 2: ";
    for (int i = 0; i < pathSize1; i++) {
        for (int j = 0; j < pathSize2; j++) {
            if (path1[i] == path2[j]) {
                cout << path1[i] << " ";
                break;
            }
        }
    }
    cout << endl;
}

// Ham tim diem giao nhau giua 2 robot, robot khac khong duoc di lai
void findIntersectionDistinct(int grid[MAX_SIZE][MAX_SIZE], int x1, int y1, int x2, int y2) {
    int grid1[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            grid1[i][j] = grid[i][j];
        }
    }

    int score1 = 0;
    int path1[MAX_SIZE * MAX_SIZE];
    int pathSize1 = 0;
    moveRobot(grid1, x1, y1, score1, path1, pathSize1);

    int score2 = 0;
    int path2[MAX_SIZE * MAX_SIZE];
    int pathSize2 = 0;
    moveRobot(grid1, x2, y2, score2, path2, pathSize2);

    cout << "Duong di c?a Robot 1: ";
    for (int i = 0; i < pathSize1; i++) {
        cout << path1[i] << " ";
    }
    cout << endl;

    cout << "Duong di c?a Robot 2: ";
    for (int i = 0; i < pathSize2; i++) {
        cout << path2[i] << " ";
    }
    cout << endl;
    cout << endl;
}

// Ham doc du lieu tu file input
void readFile(ifstream& inputFile) {
    if (!inputFile) {
        cout<<"Khong the mo file, vui long kiem tra lai du lieu."<<endl;
    } else {
        cout<<"doc file thanh cong"<<endl;
    }
}

// Ham ghi ket qua vao file output
bool writeOutputFile(int grid[MAX_SIZE][MAX_SIZE]) {
    ofstream outputFile("output.txt");
    if (!outputFile) {
        cout << "Khong the mo file output.txt";
        return false;
    }

    int score = 0;
    int path[MAX_SIZE * MAX_SIZE];
    int pathSize = 0;
     int grid1[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            grid1[i][j] = grid[i][j];
        }
    }
    
    moveRobot(grid1, 0, 0, score, path, pathSize);
    outputFile << pathSize << endl;
    for (int i = 0; i < pathSize; i++) {
        outputFile << path[i] << " ";
    }
    outputFile.close();
    return true;
}

// Ham tao bieu do di chuyen cua 2 robt va hien thi visualize duong di robot
void visualizeRobot(int grid[MAX_SIZE][MAX_SIZE], int x1, int y1, int x2, int y2, int rows, int cols) {
    int grid1[MAX_SIZE][MAX_SIZE];
    int grid2[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            grid1[i][j] = grid[i][j];
            grid2[i][j] = grid[i][j];
        }
    }

    int score1 = 0;
    int path1[MAX_SIZE * MAX_SIZE];
    int pathSize1 = 0;
    moveRobot(grid1, x1, y1, score1, path1, pathSize1);

    int score2 = 0;
    int path2[MAX_SIZE * MAX_SIZE];
    int pathSize2 = 0;
    moveRobot(grid2, x2, y2, score2, path2, pathSize2);

    cout << "Duong di c?a Robot 1: ";
    for (int i = 0; i < pathSize1; i++) {
        cout << path1[i] << " ";
    }
    cout << endl;

    cout << "Duong di c?a Robot 2: ";
    for (int i = 0; i < pathSize2; i++) {
        cout << path2[i] << " ";
    }
    cout << endl;

    // Hien thi ma tran va bieu do di chuyen
    cout << "Ma tran hien tai:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == x1 && j == y1) {
                cout << "R1 ";
            } else if (i == x2 && j == y2) {
                cout << "R2 ";
            } else {
                cout << grid[i][j] << " ";
            }
        }
        cout << endl;
    }

    cout << "Duong di cua Robot 1:\n";
    for (int i = 0; i < pathSize1; i++) {
        grid1[x1][y1] = path1[i];
        cout << "Buoc " << i + 1 << ":\n";
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                cout << grid1[r][c] << " ";
            }
            cout << endl;
        }
        if (i < pathSize1 - 1) {
            int nextX = -1, nextY = -1;
            if (isValidCell(x1 - 1, y1, rows, cols) && grid1[x1 - 1][y1] == path1[i + 1]) {
                nextX = x1 - 1;
                nextY = y1;
            } else if (isValidCell(x1 + 1, y1, rows, cols) && grid1[x1 + 1][y1] == path1[i + 1]) {
                nextX = x1 + 1;
                nextY = y1;
            } else if (isValidCell(x1, y1 - 1, rows, cols) && grid1[x1][y1 - 1] == path1[i + 1]) {
                nextX = x1;
                nextY = y1 - 1;
            } else if (isValidCell(x1, y1 + 1, rows, cols) && grid1[x1][y1 + 1] == path1[i + 1]) {
                nextX = x1;
                nextY = y1 + 1;
            }
            cout << "Di chuyen tu (" << x1 << ", " << y1 << ") den (" << nextX << ", " << nextY << ")\n";
            x1 = nextX;
            y1 = nextY;
        }
    }

    cout << "Duong di cua Robot 2:\n";
    for (int i = 0; i < pathSize2; i++) {
        grid2[x2][y2] = path2[i];
        cout << "Buoc " << i + 1 << ":\n";
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                cout << grid2[r][c] << " ";
            }
            cout << endl;
        }
        if (i < pathSize2 - 1) {
            int nextX = -1, nextY = -1;
            if (isValidCell(x2 - 1, y2, rows, cols) && grid2[x2 - 1][y2] == path2[i + 1]) {
                nextX = x2 - 1;
                nextY = y2;
            } else if (isValidCell(x2 + 1, y2, rows, cols) && grid2[x2 + 1][y2] == path2[i + 1]) {
                nextX = x2 + 1;
                nextY = y2;
            } else if (isValidCell(x2, y2 - 1, rows, cols) && grid2[x2][y2 - 1] == path2[i + 1]) {
                nextX = x2;
                nextY = y2 - 1;
            } else if (isValidCell(x2, y2 + 1, rows, cols) && grid2[x2][y2 + 1] == path2[i + 1]) {
                nextX = x2;
                nextY = y2 + 1;
            }
            cout << "Di chuyen tu (" << x2 << ", " << y2 << ") den (" << nextX << ", " << nextY << ")\n";
            x2 = nextX;
            y2 = nextY;
        }
    }
}

// Ham thuc hien di chuyen tung buoc cua 2 robot 
void stepByStep(int grid[MAX_SIZE][MAX_SIZE], int x1, int y1, int x2, int y2, int rows, int cols) {
    int grid1[MAX_SIZE][MAX_SIZE];
    int grid2[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            grid1[i][j] = grid[i][j];
            grid2[i][j] = grid[i][j];
        }
    }

    int score1 = 0;
    int path1[MAX_SIZE * MAX_SIZE];
    int pathSize1 = 0;
    moveRobot(grid1, x1, y1, score1, path1, pathSize1);

    int score2 = 0;
    int path2[MAX_SIZE * MAX_SIZE];
    int pathSize2 = 0;
    moveRobot(grid2, x2, y2, score2, path2, pathSize2);

    cout << "Duong di c?a Robot 1: ";
    for (int i = 0; i < pathSize1; i++) {
        cout << path1[i] << " ";
    }
    cout << endl;

    cout << "Duong di c?a Robot 2: ";
    for (int i = 0; i < pathSize2; i++) {
        cout << path2[i] << " ";
    }
    cout << endl;

    cout << "Vi tri trung giua Robot 1 va Robot 2: ";
    for (int i = 0; i < pathSize1; i++) {
        for (int j = 0; j < pathSize2; j++) {
            if (path1[i] == path2[j]) {
                cout << path1[i] << " ";
                break;
            }
        }
    }
    cout << endl;

    // Mo phong tung buoc di chuyen
    // M� ph?ng t?ng bu?c di chuy?n
    cout << "Mo phong tung buoc di chuyen:\n";
    int step = 0;
    while (step < max(pathSize1, pathSize2)) {
        cout << "Buoc " << step + 1 << ":\n";
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (r == x1 && c == y1) {
                    cout << "R1 ";
                } else if (r == x2 && c == y2) {
                    cout << "R2 ";
                } else {
                    cout << grid[r][c] << " ";
                }
            }
            cout << endl;
        }

        if (step < pathSize1) {
            int nextX = -1, nextY = -1;
            if (isValidCell(x1 - 1, y1, rows, cols) && grid1[x1 - 1][y1] == path1[step]) {
                nextX = x1 - 1;
                nextY = y1;
            } else if (isValidCell(x1 + 1, y1, rows, cols) && grid1[x1 + 1][y1] == path1[step]) {
                nextX = x1 + 1;
                nextY = y1;
            } else if (isValidCell(x1, y1 - 1, rows, cols) && grid1[x1][y1 - 1] == path1[step]) {
                nextX = x1;
                nextY = y1 - 1;
            } else if (isValidCell(x1, y1 + 1, rows, cols) && grid1[x1][y1 + 1] == path1[step]) {
                nextX = x1;
                nextY = y1 + 1;
            }
            cout << "Robot 1 di chuyen tu (" << x1 << ", " << y1 << ") den (" << nextX << ", " << nextY << ")\n";
            x1 = nextX;
            y1 = nextY;
        }

        if (step < pathSize2) {
            int nextX = -1, nextY = -1;
            if (isValidCell(x2 - 1, y2, rows, cols) && grid2[x2 - 1][y2] == path2[step]) {
                nextX = x2 - 1;
                nextY = y2;
            } else if (isValidCell(x2 + 1, y2, rows, cols) && grid2[x2 + 1][y2] == path2[step]) {
                nextX = x2 + 1;
                nextY = y2;
            } else if (isValidCell(x2, y2 - 1, rows, cols) && grid2[x2][y2 - 1] == path2[step]) {
                nextX = x2;
                nextY = y2 - 1;
            } else if (isValidCell(x2, y2 + 1, rows, cols) && grid2[x2][y2 + 1] == path2[step]) {
                nextX = x2;
                nextY = y2 + 1;
            }
            cout << "Robot 2di chuyen tu (" << x2 << ", " << y2 << ") den (" << nextX << ", " << nextY << ")\n";
            x2 = nextX;
            y2 = nextY;
        }

        step++;
    }
}

int main() {
    ifstream inputFile("input.txt");
    readFile(inputFile);
    int rows, cols;
    inputFile >> rows >> cols;
    int grid[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            inputFile >> grid[i][j];
        }
    }
    inputFile.close();
    int choice;
    bool isStop = true;
	while(isStop) {
		 cout << "*************************************************************************************\n";
        cout << "*                   CHAO MUNG BAN DEN VOI TRO CHOI TIM DUONG DI ROBOT               *\n";
        cout << "*   ROBOT chi duoc di chuyen trai-phai-len-xuong voi quy tac chon o co gia tri ma   *\n";
        cout << "*  trong cac o xung quanh cho den khi het ma tran                                   *\n";
        cout << "*  Voi file Input.txt chua ma tran (ban co the vao file de thay doi neu muon)       *\n";
        cout << "*  Nhap lua chon cua ban de co the choi tro choi:                                   *\n";
        cout << "*  Cach choi: Nhap toa do ban dau cua 1 hoac 2 ROBOT va lua chon duoi de bat dau :  *\n";
        cout << "*  Nhan 1.(C1) :: In ra trong so va duong di ROBOT va dua ket qua vao Output.txt    *\n";
        cout << "*  Nhan 2.(C2) :: In ra diem trung nhau va tim ROBOT thang (trong so lon hon)       *\n";
        cout << "*  Nhan 3.(C3) :: In ra duong di cua 2 ROBOT sao cho khong trung nhau               *\n";
        cout << "*  Nhan 4.(C4) :: In ra visualize duong di cua 2 ROBOT 			            *\n";
        cout << "*  Nhan 5.(C5) :: Mo phong step by step duong di cua 2 ROBOT                        *\n";
        cout << "*  Nhan 0. Ket thuc chuong trinh                                                    *\n";
        cout << "*************************************************************************************\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                writeOutputFile(grid);
                cout << "Ket qua da duoc luu vao file output.txt" << endl;
                break;
            }
            case 2: {
                int x1, y1, x2, y2;
                cout << "Nhap toa do cua Robot-1(x1, y1) = ";
                cin >> x1 >> y1;
                cout << "Nhap toa do cua Robot-2(x2, y2) = ";
                cin >> x2 >> y2;
                findIntersection(grid, x1, y1, x2, y2);
                break;
            }
            case 3: {
                int x1, y1, x2, y2;
                cout << "Nhap toa do cua Robot-1(x1, y1) = ";
                cin >> x1 >> y1;
                cout << "Nhap toa do cua Robot-2(x2, y2) = ";
                cin >> x2 >> y2;
                findIntersectionDistinct(grid, x1, y1, x2, y2);
                break;
            }
            case 4: {
                int x1, y1, x2, y2;
                cout << "Nhap toa do cua Robot-1(x1, y1) = ";
                cin >> x1 >> y1;
                cout << "Nhap toa do cua Robot-2(x2, y2) = ";
                cin >> x2 >> y2;
                visualizeRobot(grid, x1, y1, x2, y2, rows, cols);
                break;
            }
            case 5: {
                int x1, y1, x2, y2;
                cout << "Nhap toa do cua Robot-1(x1, y1) = ";
                cin >> x1 >> y1;
                cout << "Nhap toa do cua Robot-2(x2, y2) = ";
                cin >> x2 >> y2;
                stepByStep(grid, x1, y1, x2, y2, rows, cols);
                break;
            }
            case 0: {
            	 cout << "Chuong trinh ket thuc.\n";
            	isStop = false;
				break;
			}
            default:
                cout << "Lua chon khong hop le, vui long thu lai." << endl;
                break;
        }
        if (isStop)
        {
            char playAgain;
            cout << "Ban muon choi tiep khong? (y/n): ";
            cin >> playAgain;
            if (playAgain != 'y' && playAgain != 'Y')
            {
                isStop = false;
                cout << "Chuong trinh ket thuc.\n";
            }
        }
}
    return 0;
    
}

