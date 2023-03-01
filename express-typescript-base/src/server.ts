import App from './app';
import HelloWorldController from './controllers/hello-world.controller';



const app = new App(
  [
    new HelloWorldController()
  ],
);

app.listen();