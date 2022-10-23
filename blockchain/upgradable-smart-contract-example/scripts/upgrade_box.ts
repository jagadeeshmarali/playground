// scripts/upgrade_box.js
const { ethers, upgrades } = require('hardhat');

async function main() {
  const BoxV2 = await ethers.getContractFactory('BoxV2');
  console.log('Upgrading Box...');
  await upgrades.upgradeProxy('0x2FcFaaDD202E1BC8B0D5bd701f0050203C70EaEf', BoxV2);
  console.log('Box upgraded');
}

main();