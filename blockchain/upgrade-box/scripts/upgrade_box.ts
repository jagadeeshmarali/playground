import { ethers, upgrades } from 'hardhat';

async function main() {
  const BoxV2 = await ethers.getContractFactory("BoxV2");
  let box = await upgrades.upgradeProxy("0xa73188A4ba0bfc765c715F9dA36E3F947F8489a0", BoxV2);
  console.log("Box Contract upgraded", box.address)
}
main();