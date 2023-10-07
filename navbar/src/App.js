import { Route, Routes } from "react-router-dom";
import "./App.css";
import { Navbar } from "./components/Navbar";
import { About, Contact, Home, Services } from "./components/pages";
import { Kiwi } from "./Kiwi";

function App() {
  return (
    <div className="App">
      <Navbar />
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/about" element={<About />} />
        <Route path="/services" element={<Services />} />
        <Route path="/contact" element={<Contact />} />
      </Routes>
    </div>
  );
}

export default App;

// import { OrbitControls } from "@react-three/drei";
// import { Canvas } from "@react-three/fiber";
// import { Kiwi } from "./Kiwi";
// import "./App.css";

// function ThreeScene() {
//   return (
//     <>
//       <ambientLight />
//       <pointLight position={[5, 5, 5]} intensity={1} />
//       <pointLight position={[-3, -3, 2]} />
//       <OrbitControls />

//       <Kiwi />
//     </>
//   );
// }

// function App() {
//   return (
//     <div className="App h-screen">
//       <Canvas>
//         <ThreeScene />
//       </Canvas>
//     </div>
//   );
// }

// export default App;