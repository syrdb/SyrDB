- [ ] Write `Core`
    > `Core` is main component of SyrDB.
    - [ ] Write `Security module`
        > Security module. All security operations go through it.

    - [x] Write `Logger`
        > Logger needed for informate database users of current state and display warnings, errors or debug information. 

    - [ ] Write `Task Manager`
        > In order not to lose data when writing or not to give out-of-date data after reading, all tasks are performed in turn. To implement this queue, this manager is needed.

    - [ ] Write `Semi-Smart Cache Manager`
        > For more speed, we need a cache. This manager controls it and makes sure that it does not take up too much space.

    - [ ] Write `WebPanel Manager`
        > Manager of WebPanel. Work together with task and cache managers. 

    - [ ] Write TCP Server & Client
        > `Server` for SDBP[^1] and HTTP(S) WebPanel. 
        > `Client` for transfer from any NoSQL databases. 
        
        - [ ] Write `TCP Socket`
            > Usually, tools for working with the network are built into the API of the system, but I do not need a dependency on system. 

        - [ ] Write `TCP Connection`
            > This type (or class) using for storage the connection to/from SyrDB Server. 

        - [ ] Write `Connection Manager`
            > We have connection objects, but we need to work with they. This class needed for this. 

        - [ ] Write `TCP Interface`
            > Interface for working with network by TCP. 

        - [ ] Add SSL/TLS support to the server and client
            > For more secure we need to use SSL or TLS. 
            
    - [ ] Write some utils.
        > For convenience, we need utilities. For example, to split strings by characters.

        - [x] String utils
            > Some utils for working with strings. 

        - [x] Binary *(or Bytes)* utils
            > Some utils for working with bytes. 

        - [ ] RegExp utils
            > Some utils for working with regex. 

        - [ ] Data utils
            > Some utils for working with data. 

- [ ] Write `Codecs`
    > Codecs is encoders and decoders of data for various purposes.
    
    - [ ] `YAML`
        > YAML is best markup language for configs. We need to use YAML 1.2 or later. 

    - [ ] `BSON`
        > BSON is open format for storage data in binary. Used in MongoDB. 

    - [ ] `BDSFmt`
        > BDSfmt is my open format for storage data in binary. It uses less space than BSON. Prefer to use in this database. 

    - [ ] `SDBP`[^1]
        > Protocol of this database. Used to communicate between the client and the server.

    - [ ] `SQL`
        > Best format for storage data for non-dynamic *(by fields)* data. 

    - [ ] `HTTP`
        > HTTP used for communicate between the webbrowser and the server. We need to support HTTP 1.1; 2.0 and 3.0. 

- [ ] Collections and database types
    > All collections and databases has "type". Type is storage structure format. For example, NoSQL:key-value. 

    - [ ] NoSQL
        > NoSQL databases is dynamic by fields databases. All data stored as dictionary or map. 

        - [ ] Key-Value
            > One dictionary or map without another dictionaries or maps in value. 

        - [ ] Document(s)
            > The data can be of any type. And data can be has document in value in the next update of BDSFmt

    - [ ] SQL
        > SQL databases is non-dynamic by fields databases. All data stored as tables. 

- [ ] WebPanel
    > Easy-to-use and fredly web interface for working with this database. 

    - [ ] Pages
        > HTML Files of panel. 

    - [ ] Styles
        > CSS Files of panel. 

    - [ ] Scripts
        > JS Files of panel.

    - [ ] "Transfer from ..." tool
        > Transfer all data from another databases for fast start. 

        - [ ] MongoDB
        - [ ] SQLite3
        - [ ] PostgreSQL
        - [ ] MySQL
        - [ ] MariaDB

    - [ ] Connect the panel to the server.
        > For this we need to write `WebPanel Manager`

- [ ] Final testing
    - [ ] On Windows
    - [ ] On MacOS
    - [ ] On Linux
    - [ ] On Solaris

- [ ] Write official drivers (modules) for working with this database. 
    - [ ] C++
    - [ ] Python
    - [ ] Java
    - [ ] JS (Node.JS)

[^1]: SDBP - SyrDB Protocol. Protocol of this database.