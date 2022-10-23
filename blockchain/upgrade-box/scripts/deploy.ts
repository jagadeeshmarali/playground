import { ethers, upgrades } from 'hardhat';

async function main() {
  const Box = await ethers.getContractFactory("Box");
  console.log("Deploying Box...")
  let box = await upgrades.deployProxy(Box, [42], { initializer: "store" });
  await box.deployed();
  console.log("Box Contract Deployed to: ", box.address);

}

main();