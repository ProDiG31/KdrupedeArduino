const { Router } = require('express');
const bodyParser = require('body-parser');

const authRouter = Router();
const Models = require('../DataModel/index');

authRouter.use(bodyParser.urlencoded({
  extended: true
}));

authRouter.post('/login', async function(req, res){
  const { body :{username, password} } = req;
  const user = await Models.User.getAuthenticated(username, password);

  console.log("user authenticated");
  console.log(user);

  if (user.id == undefined) {
    res.status(401);
    res.json({
      msg: 'Error',
    });
    res.end();
  }

  const responseJson = {
    id: user.id,
    username: user.username,
    firstName: user.firstname,
    lastName: user.name,
    token: 'fake-jwt-token',
  };

  console.log(responseJson);

  res.status(200);
  // res.json({ ok: true, user: responseJson });
  res.redirect('/dashboard');
  res.end();
});

module.exports = authRouter;
