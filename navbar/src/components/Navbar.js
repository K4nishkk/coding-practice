import React, { useState } from "react";
import Hamburger from "hamburger-react";

import "./Navbar.css";
import { Link, NavLink } from "react-router-dom";

export const Navbar = () => {
  const [menuOpen, setMenuOpen] = useState(false); // for mobile view hamburger menu

  return (
    <nav>
      <Link to="/" className="logo"> 
        Logo
      </Link>

      <div className="menu" onClick={() => setMenuOpen(!menuOpen)}> 
        <Hamburger />
      </div>

      <ul className={menuOpen ? "open" : ""}> 
        <li>
          <NavLink to="/about">About</NavLink>
        </li>
        <li>
          <NavLink to="/services">Services</NavLink>
        </li>
        <li>
          <NavLink to="/contact">Contact</NavLink>
        </li>
      </ul>
    </nav>
  );
};