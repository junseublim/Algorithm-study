const fs = require('fs');
let k = fs.readFileSync('/dev/stdin').toString().split('\n');

let num = parseInt(k[0]);
[...k[1]].reverse().forEach(c => {
    console.log(num * parseInt(c));
})
console.log(num * parseInt(k[1]));