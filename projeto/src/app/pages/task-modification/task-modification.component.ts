import { Component } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';
import { TaskService } from 'src/app/services/task/task.service';
import { Task } from 'src/app/task';

@Component({
  selector: 'app-task-modification',
  templateUrl: './task-modification.component.html',
  styleUrls: ['./task-modification.component.css']
})
export class TaskModificationComponent {

  currentTask?: Task;

  isFormCompleted: boolean = false;

  constructor(private activatedRoute: ActivatedRoute, private taskService: TaskService, private route: Router) { }

  ngOnInit() {
    this.getTask();
  }

  isCompleted() {
    if (this.currentTask!.content.length > 0 && this.currentTask?.category !== null) {
      this.isFormCompleted = true;
    } else {
      this.isFormCompleted = false;
    }
  }

  updateTask(updatedTask: Task) {
    this.currentTask = updatedTask;
    this.isCompleted();
  }

  getTask() {
    const id = Number(this.activatedRoute.snapshot.paramMap.get('id'));
    this.currentTask = this.taskService.getTaskById(id);
  }

  sendUpdateTask() {
    this.taskService.updateTask(this.currentTask!);
    this.route.navigate([""]);
  }

}
