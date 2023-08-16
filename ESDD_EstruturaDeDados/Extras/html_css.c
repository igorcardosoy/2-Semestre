#include <stdio.h> 
#include <stdlib.h> 

int main( void ) 
{ 
  FILE      *html = fopen( "index.html", "w");

  fprintf(html, "<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"><table><thead><tr><th colspan=\"5\">Métodos de ordenação</th></tr></thead><tbody><tr><td>Metodos</td><td>Quantidade</td><td>Tempo</td><td>Comparações</td><td>Trocas</td></tr><tr><td rowspan=\"3\">BubbleSort</td><td>aaaaa</td><td>aaaaa</td><td>aaaaaa</td><td>aaaaaaa</td></tr><tr><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td></tr><tr><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td></tr><tr><td rowspan=\"3\">SelectionSort</td><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td></tr><tr><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td></tr><tr><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td></tr><tr><td rowspan=\"3\">InsertSort</td><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td></tr><tr><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td></tr><tr><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td></tr><tr><td rowspan=\"3\">QuickSort</td><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td></tr><tr><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td></tr><tr><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td></tr><tr><td rowspan=\"3\">MergeSort</td><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td></tr><tr><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td></tr><tr><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td><td>aaaaaaa</td></tr></tbody></table>");

  FILE      *css = fopen( "style.css", "w");

  fprintf(css, "body, html { margin: 0; padding: 0; display: flex; align-items: center; justify-content: center; background-color: #c0c0c0; font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; } table, td, th{ border: 1px solid black; border-collapse: collapse; text-align: center; background-color: whitesmoke; padding: 3px; }");
  
  
}