import { Router, Request, Response, NextFunction } from 'express';
import Controller from '../interfaces/controller.interface';


class HelloWorldController implements Controller {
  public path = '/hello-world';
  public router = Router();

  constructor() {
    this.initializeRoutes();
  }

  private initializeRoutes() {
    this.router.get(`${this.path}`, this.helloWorld);
  }

  private helloWorld = async (request: Request, response: any): Promise<void> => {
    response.send("Hello World");

  }

}

export default HelloWorldController;