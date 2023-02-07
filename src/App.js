
import './App.css';
import Main from './main';
import About from './about';
import Imcard from './imcard';
import Text from './text.js';
import Block from './block';
import Textrev from './textrev';
import Product from './product';
import Elem from './elem';
import Product2 from './product2';
function App() {
  return (
    <div className="App">
      <Main/>
      <About/>
      <Imcard/>
      <Text/>
      <Block/>
      {/* <Textrev/> */}
      <Product/>
      <Elem/>
//       <Product2/>
   
     
    </div>
  );
}

export default App;
