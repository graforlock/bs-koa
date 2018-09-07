open Koa;
open Route;
open Websocket; 

let app: Socket.ws(string, string) = Socket.make(App.make ());
let route = Route.route;

Socket.use(app##ws,(ctx, next) => {
  ctx##websockets##send("Hood Nigga");
  next();
});

Socket.listen(app, ~port=3000, ~callback=_ => Js.log({j|Listening on port 3000|j}));
