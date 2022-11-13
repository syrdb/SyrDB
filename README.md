<h1 align="center">
    <img alt="Logo" src="./images/logo.svg" height="45px">
</h1>

<p align="center">
    <a href="https://github.com/TheStngularity/SyrDB">
        <img alt="Version" src="https://img.shields.io/github/v/tag/TheStngularity/SyrDB?color=EF2152&label=Version">
    </a>
    <a href="https://github.com/TheStngularity/SyrDB">
        <img alt="C++" src="https://img.shields.io/badge/C++-20-EF2152">
    </a>
    <a href="https://github.com/TheStngularity/SyrDB">
        <img alt="Platform" src="https://img.shields.io/badge/Platform-Win32-EF2152">
    </a>
    <a href="https://github.com/TheStngularity/SyrDB">
        <img alt="License" src="https://img.shields.io/badge/License-BSL-EF2152">
    </a>
</p>

<p align="center">
    <a href="https://discord.gg/886NskXMxg">
        <img alt="Discord" src="https://img.shields.io/discord/1041037527047475210?color=5865F2&label=&logo=discord&logoColor=F2F2F2">
    </a>
</p>

<p align="center">
    English •
    <a href="./i18n/README_ru.md">Русский</a>
</p>

<h1>Notification</h1>
This project is WIP <em>(<strong>W</strong>ork <strong>I</strong>n <strong>P</strong>rogress)</em>. At the moment this project is not even a database, but soon (or not) it will be a full-fledged database.

<h1>What is SyrDB?</h1>
<strong>SyrDB</strong> is a new database created for a wide variety of projects, it supports <code>SQL</code> and <code>NoSQL</code>. If you are migrating from another database to this one, then the migration from other databases feature will help you!

<h1>Features</h1>

- [ ] WebPanel
- [ ] Supports **NoSQL** & **SQL**
- [x] Low resource consumption

<h1>Building</h1>
<h3>Build on Windows</h3>
<h4>Requirements</h4>

- CMake `3.12+`. **Tested:** CMake `3.24`
- Visual Studio `2019`. **Tested:** Visual Studio `2022`

1. Open console
2. Write the following commands:
> ```sh
> $ git clone https://github.com/TheStngularity/SyrDB.git
> $ cd SyrDB
> $ mkdir build
> $ cd build
> $ cmake .. -DCMAKE_BUILD_TYPE=Release
> $ cmake --build . --config Release
> $ move src/Release/syrdb.exe ./syrdb.exe
> ```

Ready! Database builed.

<h3>Build on Linux</h3>
<h4>Requirements</h4>

- CMake `3.12+`. **Tested:** CMake `3.24`
- G++

1. Open terminal
2. Write the following commands:
> ```sh
> $ git clone https://github.com/TheStngularity/SyrDB.git
> $ cd SyrDB
> $ mkdir build
> $ cd build
> $ cmake .. -DCMAKE_BUILD_TYPE=Release
> $ cmake --build . --config Release
> $ move src/syrdb ./syrdb
> ```

<h1>Getting started</h1>
To get started with this database, you need to select any driver and write code according to the documentation.

<h5>List of available drivers:</h5>

- [ ] JavaScript
- [ ] Node.JS
- [ ] Python
- [ ] C++
- [ ] Java
- [ ] .NET

<h1>License</h1>
The source code for this database is distributed under the <code>BSL</code> <em>(Business Source License)</em> license. See the <a href="./LICENSE">LICENSE</a> file for more information.
