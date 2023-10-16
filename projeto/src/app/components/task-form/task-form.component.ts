import { Component, EventEmitter, Input, Output } from '@angular/core';
import { TaskService } from 'src/app/services/task/task.service';
import { Task } from 'src/app/task';

@Component({
  selector: 'app-task-form',
  templateUrl: './task-form.component.html',
  styleUrls: ['./task-form.component.css']
})
export class TaskFormComponent {

  categoryType: string[] = ["shopping", "health", "work", "bills", "cleaning", "other"];

  @Input() currentTask?: Task;

  @Output() updateTask = new EventEmitter();

  constructor(private taskService: TaskService) { }

  updateContent(value: string): void {
    this.taskService.changeTaskContent(this.currentTask!, value)
    this.updateTask.emit(this.currentTask);
  }

  chooseCategory(category: string) {
    this.taskService.changeTaskCategory(this.currentTask!, category);    
    this.updateTask.emit(this.currentTask);
  }

  changePriority() {
    this.taskService.changeTaskPriority(this.currentTask!);
    this.updateTask.emit(this.currentTask);
  }

}
