import { isNgTemplate } from '@angular/compiler';
import { TaskService } from '../../services/task/task.service';
import { Component } from '@angular/core';
import { Task } from 'src/app/task';

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.css']
})
export class HomeComponent {

  
  todoList: Task[] = [];
  
  nonUrgentTasksExisitis: boolean = false;
  urgentTasksExistis: boolean = false;
  
  constructor(private taskService: TaskService) {}
    
    ngOnInit() {
      this.todoList = this.getTodoList();
      this.checkTaskPriority(this.todoList);
    }
    
    getTodoList(){
      return this.taskService.getUnDoneTasks();
    }


    checkTaskPriority(todoList: Task[]){
      if(todoList.map((item) => item.isUrgent).includes(true)){
        this.urgentTasksExistis = true;
      } else{  
        this.urgentTasksExistis = false;
      }

      if(todoList.map((item) => item.isUrgent).includes(false)){
        this.nonUrgentTasksExisitis = true;
      } else{  
        this.nonUrgentTasksExisitis = false;
      }
    }


    setTaskIsDone(task: Task){
      this.taskService.setAsDone(task);
      this.todoList = this.getTodoList();
      this.checkTaskPriority(this.todoList);
    }


    filterCategories(taskList: Task[]) {
      this.todoList = taskList;
      this.checkTaskPriority(this.todoList);
    }








}
