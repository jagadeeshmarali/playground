import React, { useState } from 'react';

function App() {
  let [count,updateCount] = useState(()=>{
    return 4;
  }); 
  function sub(){
    updateCount(prev=>prev-1)
  }
  function add(){
    updateCount(prev=>prev+1)
  }
  return (
    
    <div>
    <div>Counter</div>
    <button onClick={sub}>-</button>
    <span>{count}</span>
    <button onClick={add}>+</button>
    </div>
  );
}

export default App;
