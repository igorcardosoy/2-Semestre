/*
    One of the most frequent operations in computation is to sort a sequence of objects. So it is not surprising that this operation is also one of the most studied.

    A simple algorithm for sorting is called Bubblesort. It consists of several turns. At each turn the algorithm simply iterates over the sequence switching sides two consecutive elements if they are out of order. The algorithm terminates when no element shifted in one turn.

    The name Bubblesort (sort of bubbles) derives from the fact that smaller elements ("lighter elements") move toward their final positions in the sorted sequence (move toward the beginning of the sequence) during shifts, like air bubbles in water. The figure below shows an implementation of the algorithm in pseudocode:

    For i from 1 to N do
    For j from N - 1 to i do
        If seq [j - 1]> seq [j] then
        Interchange elements seq [j - 1], and seq [j]
        End-If
    End-For
    If no element switched places
        End of algorithm
    End-If
    End-For

    For example, to sort the sequence [5, 4, 3, 2, 1] using the above algorithm, four shifts are required. In the first round four exchanges occur: 1 x 2, 1 x 3, 1 x 4 and 1 x 5, in the second part there are three exchanges 2 x 3, 2 x 4 and 2 x 5, in the third round two exchanges occur: 3 x 4 and 3 x 5; in the fourth shift there is only one exchange: 4 x 5, in the fifth round no exchange occurs and the algorithm terminates.

    Although simple to understand, implement and prove correct, the bubblesort algorithm is very inefficient: the number of comparisons between elements during its execution is, on average, proportional to N2, where N is the number of elements in the sequence. You have been asked to do a "reverse engineering" of the bubblesort, ie, given the length of the sequence, the number of shifts required to sort and the number of exchanges that occurred at every turn, your program must find a possible sequence, when sorted, produces exactly the same number of exchanges in shifts.

    Input
    The input contains several test cases. The first line of a test case contains two integers N and M respectively indicate that the number of elements (1 ≤ N ≤ 100,000) in the sequence that is being ordered, and the number of turns (0 ≤ M ≤ 100,000) needed to sort the sequence using bubblesort. The second line of a test case contains M integers Xi, indicating the number of exchanges in each round i (1 ≤ Xi ≤ N - 1, for 1 ≤ i ≤ M). The end of input is indicated by N = M = 0.

    Output
    For each test case in the input your program must produce one line of output, containing a permutation of the numbers {1, 2, ..., N}, which when sorted using bubblesort produces the same number of exchanges in the same number of turns specified at the input. When printing the permutation, leave a blank space between consecutive elements. If more than one permutation exists, then print the largest in lexicographic order to standard number sequences (lexicographic order of the permutation a1, a2, ..., aN is greater than the permutation b1, b2, ..., bN is for some 1 ≤ i ≤ N we have ai> bi and prefix a1, a2, ..., ai-1 is equal to the prefix b1, b2, ..., bi-1).

    In other words, if there is more than one solution, print the one in which the first element permutation is as large as possible. If there is more than one solution satisfying this constraint, print, among them, the one where the second element is the largest possible. If there is more than one solution satisfying the above two constraints, printing, among these, the solution where the third element is as large as possible, and so forth.

    For every entry there will be at least one permutation solution.
*/

#include <stdio.h>

void bubbleEstranho(int size, int turnos);

int main()
{

    int turnos = 1, size = 1;

    while (size != 0 && turnos != 0) {
        scanf("%d %d", &size, &turnos);

        bubbleEstranho(size, turnos);
    }

    return 0;
}

void bubbleEstranho(int size, int turnos)
{
    if (!size && !turnos) {
        return;
    }

    int trocou = 1;
    int trocas = 0, i = 0, j = 0, k = 0, temp = 0;

    int* array = (int) malloc(sizeof(int) * size);

    for (i = 1; i < size + 1; i++) {
        array[i - 1] = i;
    }

    for (i = 0; i < turnos; i++) {
        scanf("%d", &trocas);

        j = 0;

        while (j < trocas && trocou) {

            trocou = 0;
            if (k == 0) {
                k = size - 1;
            }

            if (turnos == 1 && trocas == 1) {
                temp = array[0];
                array[0] = array[1];
                array[1] = temp;
                j++;
                trocou = 1;
            } else if (array[k] > array[k - 1]) {
                temp = array[k];
                array[k] = array[k - 1];
                array[k - 1] = temp;
                j++;
                trocou = 1;
            }

            k--;
        }
    }

    for (i = 0; i < size; i++) {

        if (i == (size - 1)) {
            printf("%d", array[i]);
        } else {
            printf("%d ", array[i]);
        }
    }

    printf("\n");
}
