import React from 'react'
import PropTypes from 'prop-types'
import Button from "./Button"



const Header = ({onAdd, showAdd}) => {
    

    function onClick()
    {
        console.log("clicked");
    }
    
    return (
        <header className="header">
            <h1>Task Manager</h1>

            <Button onClick= {onAdd} color='black' text={showAdd ? 'Close' : 'Add'}></Button>

        </header>
    )
}

Header.defauktProps =
{
    title: 'NoUser',

}



export default Header
