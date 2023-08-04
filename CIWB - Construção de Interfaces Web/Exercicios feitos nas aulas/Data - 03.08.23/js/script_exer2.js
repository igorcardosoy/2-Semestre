var divisores;

for (let index = 56; index < 177; index++) {

    divisores = 0;

    for (let count = 1; divisores != 3 && count != index; count++) {
        if((index % count) === 0) 
        {
            divisores += 1;
        }
    }

    if (divisores !== 3) {
        document.write(index+" É primo"+"<br>");
    }
}
