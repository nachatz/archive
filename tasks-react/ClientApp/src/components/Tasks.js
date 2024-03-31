import React from 'react'
import Task from './Task'


const Tasks = ({tasks, onDelete, toggle}) => {

    return (
        <>
            {tasks.map((task) => (

                <Task key={tasks.id} toggle={toggle} onDelete={onDelete} task={task}/>

            ))}

        </>
    )
}

export default Tasks
