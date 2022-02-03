import { Component } from '@angular/core';
import { ethers } from "ethers";
declare const window: any;

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent {
  title = 'account-fetch';
  constructor() {
    this.init();

  }

  async init() {
    const provider = new ethers.providers.Web3Provider(window.ethereum)
    await window.ethereum.enable()
    let accounts = await provider.listAccounts();
    let balance = await provider.getBalance(accounts[0]);
    console.log(ethers.utils.formatEther(balance));
  }
}
