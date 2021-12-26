import { Component } from '@angular/core';
import Web3 from 'web3';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent {
  title = 'hello-world';
  message: string = "";
  web3 = new Web3('ws://localhost:8546');
  onSubmit() {
    console.log(this.message);
  }
}
