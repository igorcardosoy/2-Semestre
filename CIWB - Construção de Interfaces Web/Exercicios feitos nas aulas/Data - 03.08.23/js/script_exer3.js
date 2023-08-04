var num1 = 0;
var num2 = 1;
var aux;

document.write(num1+"<br>");
document.write(num2+"<br>");

for (let index = 2; index < 100; index++) {
    aux = num1 + num2;
    num1 = num2;
    num2 = aux;

    document.write(aux+"<br>");
}