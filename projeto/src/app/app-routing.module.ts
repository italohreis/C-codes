import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { HistoryComponent } from './pages/history/history.component';
import { HomeComponent } from './pages/home/home.component';
import { NotFoundComponent } from './pages/not-found/not-found.component';
import { TaskCreationComponent } from './pages/task-creation/task-creation.component';
import { TaskModificationComponent } from './pages/task-modification/task-modification.component';

const routes: Routes = [
  { path: "", component: HomeComponent},
  { path: "new-task", component: TaskCreationComponent},
  { path: "update-task/:id", component: TaskModificationComponent},
  { path: "history", component: HistoryComponent},
  { path: "not-found", component: NotFoundComponent},
  { path:"**", redirectTo: "not-found"}
];

@NgModule({
  imports: [RouterModule.forRoot(routes, {scrollPositionRestoration: 'enabled'})],
  exports: [RouterModule]
})
export class AppRoutingModule { }
