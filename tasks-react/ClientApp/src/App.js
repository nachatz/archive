import React, { Component } from 'react';
import Header from './components/Header'
import Tasks from './components/Tasks';
import AddTask from './components/AddTask';
import {useState} from 'react'

import './index.css';

const App = () => {

  const [showAddTask, setShowAddTask] = useState(false);

  const [tasks, setTasks] = useState([

    {
        id:1,
        text: "Coffee ",
        day: "today",
        reminder: true,
    }, 
    {
        id:2,
        text: "Meeting with boss",
        day: "tomorrow",
        reminder: false,
    },
    {
        id:3,
        text: "Eat dinner ",
        day: "tomorroww",
        reminder: false,
    }
])


function addTask(task)
{
  
  const id = Math.floor(Math.random() * 10000) + 1

  const newTask = {id, ...task}

  setTasks([...tasks, newTask])

}

  function deleteTask(id)
  {
      setTasks(tasks.filter( (task) => 
      
        task.id !== id

      ))

  }

  function toggleReminder(id)
  {
      setTasks(tasks.map((task) => 
        task.id === id ? {...task, reminder: !task.reminder} : task
      
      ))
  }

  return (
    <div className="container">
      <Header onAdd={() => setShowAddTask(!showAddTask)} showAdd={showAddTask}/>
      {showAddTask && <AddTask onAdd={addTask}></AddTask>}
      <Tasks toggle={toggleReminder} tasks={tasks} onDelete={deleteTask}/>
      
    </div>
  )
}

export default App
