//Requisitando o tamanho da area em m².
var area = prompt("Digite o temanaho da area a ser pintada (em m²): ");

//Calculo quantas latas de tinta serão necessárias. Uitilizo a função Math.ceil() para aproximar o numero sempre para cima.
var paints = Math.ceil(area / 3);

//Calculo do valor das tintas.
var paints_price = 80 * paints;

//Mostrar ao usuario os valores.
document.write("Será necessário "+ paints +" latas de tinta e custará R$"+ paints_price +".");