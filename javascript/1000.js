const fs = require('fs');
let k = fs.readFileSync('/dev/stdin').toString().split(' ');

console.log(parseInt(k[0]) + parseInt(k[1]));