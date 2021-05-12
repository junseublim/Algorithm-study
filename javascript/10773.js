const fs = require('fs');
let inp = fs.readFileSync('/dev/stdin').toString().split('\n');
let k = inp.shift();
let stack = [];
for (var i = 0; i < parseInt(k); i++) {
    if (inp[i] === "0") {
        stack.pop();
    }
    else stack.push(parseInt(inp[i]));
}

let answer = stack.reduce((a, b) => a + b, 0);

console.log(answer)