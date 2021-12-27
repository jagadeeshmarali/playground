import { Component } from '@angular/core';
import Web3 from 'web3';
import Web3Modal from "web3modal";
import { AbiItem } from 'web3-utils'
// declare let window: any;
import * as evmChains from "evm-chains"

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent {
  abi = [
    {
      "inputs": [
        {
          "internalType": "string",
          "name": "_greeting",
          "type": "string"
        }
      ],
      "stateMutability": "nonpayable",
      "type": "constructor"
    },
    {
      "inputs": [],
      "name": "greet",
      "outputs": [
        {
          "internalType": "string",
          "name": "",
          "type": "string"
        }
      ],
      "stateMutability": "view",
      "type": "function"
    },
    {
      "inputs": [
        {
          "internalType": "string",
          "name": "_greeting",
          "type": "string"
        }
      ],
      "name": "setGreeting",
      "outputs": [],
      "stateMutability": "nonpayable",
      "type": "function"
    }
  ];
  private providerOptions = {
  };
  web3Modal = new Web3Modal({
    ...this.providerOptions
  });
  title = 'hello-world';
  message: string = "";

  constructor() {


  }
  async connect() {
    try {
      await window.updateWeb3Modal({ show: true });
      let provider = await this.web3Modal.connect();
      await window.updateWeb3Modal({ show: false });
      return provider;
    } catch (error) {
      console.log(error);

    }
  }

  async onSubmit() {
    console.log(this.message);
    let provider = await this.connect();
    const web3 = new Web3(provider);
    let accounts = await web3.eth.getAccounts();
    let balance = await web3.eth.getBalance(accounts[0]);
    let chainId = await web3.eth.getChainId();
    let evmchain = await evmChains.getChainByChainId(chainId);

    const contract = new web3.eth.Contract(this.abi as AbiItem[], "0xe4E439965078d72033B2e0F8c47A5a56a3399530");
    let result = await contract.methods.greet().call();
    await contract.methods.setGreeting(this.message).send({ from: accounts[0], gas: 3000000 });
    console.log(provider);

    console.log(result);

    console.log(accounts);
    console.log(balance);
    console.log(chainId);
    console.log(evmchain);


  }
}
