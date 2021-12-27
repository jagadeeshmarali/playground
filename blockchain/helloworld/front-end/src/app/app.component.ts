import { Component } from '@angular/core';
import Web3 from 'web3';
import Web3Modal from "web3modal";
// declare let window: any;

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent {
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
    console.log(await web3.eth.getAccounts());


  }
}
