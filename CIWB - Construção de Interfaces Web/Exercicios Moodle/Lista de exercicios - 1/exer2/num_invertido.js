var num = prompt('Digite um numero de três digitos: ');

var num1 = parseInt(num / 100);
num = parseInt(num % 100);

var num2 = parseInt(num / 10);
var num3 = parseInt(num % 10);

var invertido = (num3  * 100) + (num2 * 10) + num1;

document.write(invertido);