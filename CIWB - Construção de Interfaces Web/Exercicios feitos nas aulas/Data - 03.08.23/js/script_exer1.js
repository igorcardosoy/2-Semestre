let count = 0;

for (let index = 911; index < 101000; index++) {
    if(((index % 5) === 0) && ((index % 11) === 0)) 
    {
        count += 1;
    }
}

alert(count);