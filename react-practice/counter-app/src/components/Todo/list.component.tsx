import { useEffect, useState } from "react";

function Todo(){
  let [todos,updateList] = useState([]);
  useEffect(()=>{
    fetch('https://jsonplaceholder.typicode.com/todos')
      .then(response => response.json())
      .then(json => {
        console.log(json)
        updateList(json)
      })
  },[])
  return (<>
    <div>Todo's List</div>
    {todos.map(todo=>{return <pre>{JSON.stringify(todo)}</pre>})}
  </>)
}

export default Todo;