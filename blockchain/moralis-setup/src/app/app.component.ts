
import { Component } from '@angular/core';
import { Moralis } from 'moralis';
import { environment } from '../environments/environment';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent {
  title = 'moralis-setup';
  public user: any;
  public isLoggedIn = false;
  public createdAt: any;
  public updatedAt: any;
  public ethAddress: any;
  public isAuthenticated = false;
  private moralis = Moralis;
  constructor() {
    this.moralis.start({ serverUrl: environment.moralisServerUrl, appId: environment.moralisAppId });
  }



  // Login 
  async login() {
    this.user = await this.moralis.User.current();
    if (!this.user) {
      let user = await Moralis.authenticate();
      console.log("login ==> ", user);
      this.createdAt = user.createdAt;
      this.updatedAt = user.updatedAt;
      // this.ethAddress = user.attributes.ethAddress;
    }
    this.isLoggedIn = true;
  }

  // Logout
  async logOut() {
    await this.moralis.User.logOut();
    console.log("logged out ==>");
    this.isLoggedIn = false;
  }

}
