var document_size = prompt("Digite o tamanho do arquivo (em MB): ");
var internet_velocity = prompt("Digite a velocidade de download da sua internet (em Mbps): ");

//Converter MB para Mb
document_size = document_size * 8;

//Descobrir o tempo em segundos para o download
var seconds = document_size / internet_velocity;

//Calcular o tempo em minutos e segundos
minutes = parseInt(seconds / 60);
seconds = parseInt(seconds % 60);

//Adcionar o texto no body
document.write("Pode demorar em torno de "+ minutes +" minuto(s) e "+ seconds +" segundo(s)");