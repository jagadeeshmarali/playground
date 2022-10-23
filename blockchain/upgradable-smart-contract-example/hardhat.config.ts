import "@nomicfoundation/hardhat-toolbox";
import '@nomiclabs/hardhat-etherscan';
import '@openzeppelin/hardhat-upgrades';
import dotenv from 'dotenv';
dotenv.config();
const config = {
  solidity: "0.8.9",
  networks: {
    rinkeby: {
      url: "https://rinkeby.infura.io/v3/1dc931d842b449c0a674b754ee15aafd",
      accounts: [process.env.ACCOUNT_PRIVATE_KEY]
    },
    matic: {
      url: "https://polygon-rpc.com/",
      accounts: [process.env.ACCOUNT_PRIVATE_KEY]
    },
    matic_mumbai: {
      url: "https://matic-mumbai.chainstacklabs.com",
      accounts: [process.env.ACCOUNT_PRIVATE_KEY]
    }
  },
  etherscan: {
    apiKey: process.env.POLYGONSCAN_API_KEY
  }
};

export default config;
