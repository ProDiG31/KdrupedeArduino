// Module import by npm
const express = require('express');
const bodyParser = require('body-parser');
const fs = require('fs');
const _ = require('lodash');
// const pug = require('pug');

const authRouter = require('./routes/auth');
const userRouter = require('./routes/user');

// Module instance
const app = express();
const server = require('http').createServer(app);
require('dotenv').config();

// Connection a la base de donnée
const { connect } = require('./service/dbService');

// init db connection
connect();

// Router instance
const router = express.Router();

router.use(bodyParser.urlencoded({
  extended: true
}));

router.use(bodyParser.json());

// path vers les ressources;
router.use('/css', express.static(`${__dirname}/views/css`));
router.use('/js', express.static(`${__dirname}/views/js`));
router.use('/data', express.static(`${__dirname}/views/data`));
router.use('/img', express.static(`${__dirname}/views/img`));
router.use('/template', express.static(`${__dirname}/views/template`));


// a middleware function with no mount path. This code is executed for every request to the router
router.use((req, res, next) => {
  const date = new Date();
  console.log(`[Time]: ${date.getHours()}:${date.getMinutes()}:${date.getSeconds()} - [Method]: ${req.method} [URL]: ${req.url}`);
  next();
});

// path de redirection
// Path /
router.get('/', (req, res) => {
    fs.readFile('./views/app.html', 'utf-8', (error, content) => {
      res.writeHead(200, {
        'Content-Type': 'text/html',
      });
      res.end(content);
    });
  });

  router.get('/dashboard', (req,res) => {
    fs.readFile('./views/app2.html', 'utf-8', (error, content) => {
      res.writeHead(200, {
        'Content-Type': 'text/html',
      });
      res.end(content);
    });
  })

// mount the router on the app
app.use('/auth',authRouter)
app.use('/',userRouter)
app.use('/', router);

// define listening port of server
const port = process.env.CLIENT_PORT
server.listen(port);
console.log('App Launched on post 3000 ' + port);

