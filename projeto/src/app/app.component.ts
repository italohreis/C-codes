import { Component } from '@angular/core';
import { environment } from 'src/environments/environments';
import { TaskService } from './services/task/task.service';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = environment.title;

  constructor(private taskService: TaskService) {}

  ngOnInit() {
    this.taskService.getToDos();
  }
}
