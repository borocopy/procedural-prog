const letters = 'abcdefghijklmnopqrstuvwxyz'.toUpperCase().split('');

const ans = letters
  .map((l, idx) => ({ l, v: idx + 10 }))
  .map((item) => `case ${item.v}: ans = '${item.l}';break;`);
console.log(ans.join(''));
