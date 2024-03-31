import React from 'react'
import {useState} from 'react'


const AddTask = ({onAdd}) => {

    const [text, setText] = useState('')
    const [day, setDay] = useState('')
    const [reminder, setReminder] = useState(false)

    function onSubmit(e)
    {
        e.preventDefault();

        if(!text)
        {
            alert("Add a task");
            return;
        }

        onAdd({text, day, reminder})

        setText('')
        setDay('')
        setReminder(false)

    }


    return (

        <form className="add-form" onSubmit={onSubmit}> 
            <div className ='form-control'>

                <input type='text' placeholder='Add Task' value={text} onChange={(e) => setText(e.target.value)}></input>

            </div>            
            <div className ='form-control'>

                <input type='text' placeholder='Add day and time' value={day} onChange={(e) => setDay(e.target.value)}></input>
                
            </div>            
            <div className ='form-control form-control-check'>

                <input checked={reminder} type='checkbox' value={reminder} onChange={(e) => setReminder(e.currentTarget.checked)}/>
                
            </div>

        <input className="btn btn-block" type='submit' value='Save Tast'></input>

        </form>
    )
}

export default AddTask
