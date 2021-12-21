import * as fs from 'fs/promises';

async function main() {
  const names = await fs.readdir('./data', { encoding: 'utf-8' });

  const json = names.map(
    async (x) => await fs.readFile(`./data/${x}`, { encoding: 'utf-8' })
  );

  // const am = json.

  console.log(json.length);

  // await fs.writeFile('./data.json', JSON.stringify(json), {
  //   encoding: 'utf-8',
  // });
}

main();
