import { Component, EventEmitter, Output } from '@angular/core';
import { TaskService } from 'src/app/services/task/task.service';
import { Task } from 'src/app/task';

@Component({
  selector: 'app-filter',
  templateUrl: './filter.component.html',
  styleUrls: ['./filter.component.css']
})
export class FilterComponent {

  todoList: Task[] = [];

  categoryType: string[] = ["shopping", "health", "work", "bills", "cleaning", "other"];

  @Output() changeCategory = new EventEmitter();

  constructor(private taskService: TaskService) { }

  filterCategory(category: string) {
    this.todoList = this.taskService.getUnDoneTasks();
    this.todoList = this.todoList.filter((task: any) => {
      return task.category === category;
    })
    this.changeCategory.emit(this.todoList);

    if (category === "all") {
      this.todoList = this.taskService.getUnDoneTasks();
      this.changeCategory.emit(this.todoList);
    }
  }

}
