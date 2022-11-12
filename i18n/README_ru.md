<h1 align="center">
    <img alt="Logo" src="../images/logo.svg" height="45px">
</h1>

<p align="center">
    <a href="https://github.com/TheStngularity/SyrDB">
        <img alt="Версия" src="https://img.shields.io/github/v/tag/TheStngularity/SyrDB?color=EF2152&label=%D0%92%D0%B5%D1%80%D1%81%D0%B8%D1%8F">
    </a>
    <a href="https://github.com/TheStngularity/SyrDB">
        <img alt="C++" src="https://img.shields.io/badge/C++-20-EF2152">
    </a>
    <a href="https://github.com/TheStngularity/SyrDB">
        <img alt="Платформа" src="https://img.shields.io/badge/Платформа-Win32-EF2152">
    </a>
    <a href="https://github.com/TheStngularity/SyrDB">
        <img alt="Лицензия" src="https://img.shields.io/badge/Лицензия-BSL-EF2152">
    </a>
</p>

<p align="center">
    <a href="https://discord.gg/886NskXMxg">
        <img alt="Discord" src="https://img.shields.io/discord/1041037527047475210?color=5865F2&label=&logo=discord&logoColor=F2F2F2">
    </a>
</p>

<p align="center">
    <a href="../README.md">English</a>
    • Русский
</p>

<h1>Увидомление</h1>
Это WIP <em>(<strong>англ.</strong> <strong>W</strong>ork <strong>I</strong>n <strong>P</strong>rogress)</em>. На данный момент этот проект даже не база данных, но скоро (или нет) это будет полноценная база данных.

<h1>Что такое SyrDB?</h1>
<strong>SyrDB</strong> - это новая база данных, созданная для самых разных проектов, она поддерживает <code>SQL</code> и <code>NoSQL</code>. Если вы переходите с другой базы данных на эту, то вам поможет функция "Перенос из ..."!

<h1>Функции</h1>

- [ ] Веб-панель
- [ ] Поддержка **NoSQL** & **SQL**
- [x] Низкое потребление ресурсов

<h1>Сборка</h1>
В настоящее время эта база данных поддерживает только Windows, но в будущем будет добавлена ​​поддержка Linux и macOS.

<h3>Сборка на Windows</h3>
<h4>Требования</h4>

- CMake `3.12+`. **Проверено:** CMake `3.24`
- Visual Studio `2019`. **Проверено:** Visual Studio `2022`

1. Откройте консоль
2. Пропишите следующие команды:
> ```sh
> $ git clone https://github.com/TheStngularity/SyrDB.git
> $ cd SyrDB
> $ mkdir build
> $ cd build
> $ cmake .. -DCMAKE_BUILD_TYPE=Release
> $ cmake --build .
> $ move src/Debug/syrdb.exe ./syrdb.exe
> ```

Готово! База данных собрана.

<h1>Начало работы</h1>
Для начала работы с этой базой нужно выбрать любой драйвер и написать код согласно документации.

<h5>Список доступных драйверов:</h5>

- [ ] JavaScript
- [ ] Node.JS
- [ ] Python
- [ ] C++
- [ ] Java
- [ ] .NET

<h1>Лицензия</h1>
Исходный код этой базы данных распространяется под лицензией <code>BSL</code> <em>(<strong>англ.</strong> Business Source License)</em>. Посмотрите файла <a href="../LICENSE">LICENSE</a> для получения большей информации.
