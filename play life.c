
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<conio.h>
#define SIZE 5
int arr[SIZE][SIZE];

void initializeGrid();
    int arr1[SIZE][SIZE];
    int countLiveNeighbors(int row, int col);
    void updateGrid();
    void printGrid();
    //  Инициализируйте сетку случайными значениями
    void initializeGrid() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                arr1[i][j] = rand() % 2;
            }
        }
}


int main() {
    int grid[SIZE][SIZE];
    int generation = 0;
    srand(time(NULL));//устанавливаем те кущее время как seed для генерации
    create_grid(grid);// генерируем поле
    printf("Generation %d\n", generation);
    print_grid(grid);// выводим поле
    while (1) {
        char choice;
        printf("Next generation? ( Y / N ): ");
        scanf(" %c", &choice);// генерация идёт по команде пользователя(пока не остановят командой "n" или "N")
        if ((choice == 'n') || (choice == 'N')) 
            break;
        game_of_life(grid);// проводим игру
        printf("Generation %d\n", ++generation);// выводим результат
        print_grid(grid);// выводим поле после геерации
    }
    return 0;
}

// Обновите состояние сетки
void updateGrid() {
    int newarr[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int liveNeighbors = countLiveNeighbors(i, j);
            if (arr[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                newarr[i][j] = 0;
            } else if (arr[i][j] == 0 && liveNeighbors == 3) {
                newarr[i][j] = 1;
            } else {
                newarr[i][j] = arr[i][j];
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            arr[i][j] = newarr[i][j];
        }
    }
}
// печатать сетку
void printGrid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Основная функция
int main() {
    srand(time(NULL));
    initializeGrid();

    // Распечатайте исходную сетку
    printf("Initial grid:\n");
    printGrid();

    // Обновите и распечатайте сетку в 10 разных вариациях
    for (int i = 0; i < 10; i++) {
        updateGrid();
        printf("\n");
        printGrid();
    }
    getch();
    return 0;
}