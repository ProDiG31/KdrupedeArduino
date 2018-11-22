const { Router } = require('express');
const bodyParser = require('body-parser');

const userRouter = Router();
const Models = require('../DataModel/index');

userRouter.use(bodyParser.urlencoded({
  extended: true
}));


userRouter.get('/users', async (req, res) => {
  console.log('[GET] - get all users');
  // fill user from /POST data body and save in database
  const userList = await Models.User.getAllUsers();

  if (!userList) {
    res.status(401);
    res.json({
      msg: 'Error',
    });
    res.end();
  }

  console.log(userList);
  // res.header({ 'Content-Type': 'application/json' });
  res.status(200);
  res.json({ ok: true, users: userList });
  res.end();
});

userRouter.post('/user/new', (req, res) => {
  console.log('[POST] - Creation user Handle');
  console.log(req.body)
  // const { }
  // fill user from /POST data body and save in database

  const newUser = Models.User(req.body);
  console.log(newUser.name)
  // Save new user
  console.log("Password : " + newUser.password)
  console.log("Name : " + newUser.name)
  console.log("Mail : " + newUser.mail)
  newUser.save((err) => {
    if (err) throw err;
  });
  res.status(200);
  res.json({
    msg: 'User Created',
  });
  res.end();
});

userRouter.get('/users/:username', (req, res) => {
  console.log('[GET] - Consulting user');
  //   console.log('username = ' + req.)
  Models.User.findOne({ username: req.params.username }, (err, user) => {
    if (err) throw err;

    console.log('User found');
    // console.log(res)
    console.log(user);
    res.setHeader('Content-Type', 'application/json');
    res.send(JSON.stringify(user));
    res.end();
  });
});

module.exports = userRouter;
