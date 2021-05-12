const fs = require('fs');
let k = fs.readFileSync('/dev/stdin').toString().split('\n');

let first = k.shift();

const getMax = (a, b) => Math.max(a, b);


for (var i = 0; i < parseInt(first); i++) {
    let temp = k.shift().split(' ').map(item => parseInt(item));
    let idx = temp[1];
    let numbers = k.shift().split(' ').map(item => parseInt(item));
    let cnt = 1;
    while (numbers.length > 0) {
        let front = numbers.shift();
        let maxV = numbers.reduce(getMax, 0);
        console.log(front, maxV);
        if (front < maxV) {
            numbers.push(front);

        }
        else if (idx === 0) {
            console.log(cnt);
            break;
        }
        else { cnt++; }
        if (idx !== 0) idx--;
        else idx = numbers.length - 1;


    }



}