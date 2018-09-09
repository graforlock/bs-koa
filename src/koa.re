type acceptedContent = 
  | Result(string)
  | Bool(bool);

type unknownContent;

let convertContent = s =>
  switch (Js.Types.classify(s)) {
    | JSString(s) => Result(s)
    | _ => Bool(false)
    };

type method_ =
  | Get
  | Post
  | Put
  | Delete
  | Head
  | Options
  | Trace
  | Connect;

module App = {
  type t('ws) = {. "ws": 'ws };

  type request = {.
    "header": string,
    "headers": Js.Dict.t(string),
    [@bs.set] "method": string,
    [@bs.set] "url": string,
    "originalUrl": string,
    "origin": string,
    "href": string,
    [@bs.set] "path": string,
    [@bs.set] "query": Js.Dict.t(string),
    [@bs.set] "querystring": string,
    "host": string,
    "hostname": string,
    "fresh": bool,
    "stale": bool,
    "socket": string, /* Socket object */
    "protocol": string,
    "secure": bool,
    "ip": string,
    "ips": array(string),
    "subdomains": array(string),
    [@bs.meth] "is": array(string) => string,
    [@bs.meth] "accepts": array(string) => unknownContent,
    [@bs.meth] "acceptsCharsets": array(string) => unknownContent,
    [@bs.meth] "acceptsEncodings": array(string) => unknownContent,
    [@bs.meth] "acceptsLanguages": array(string) => unknownContent,
    [@bs.meth] "get": string => string
  };

  type response('body) = {.
    [@bs.set] "body": 'body,
    [@bs.set] "status": int,
    [@bs.set] "message": string,
    [@bs.set] "length": int,
    [@bs.set] "headerSent": bool,
    [@bs.set] "lastModified": Js.Date.t,
    [@bs.set] "etag": string,
    [@bs.meth] "redirect": string => string => unit,
    [@bs.meth] "attachment": string => unit,
    [@bs.meth] "set": string => string => unit,
    [@bs.meth] "append": string => array(string) => unit,
    [@bs.meth] "remove": string => unit
  };

  type ctx('body, 'ws) = {.
    "req": request,
    "res": response('body),
    "request": request,
    "response": response('body),
    [@bs.set] "body": 'body,
    [@bs.set] "url": string,
    [@bs.set] "path": string,
    [@bs.set] "query": Js.Dict.t(string),
    [@bs.set] "querystring": string,
    "fresh": bool,
    "stale": bool,
    "idempotent": bool,
    "secure": bool,
    "socket": string, /* Socket object */
    "ip": string,
    "ips": array(string),
    "subdomains": array(string),
    "protocol": string,
    "header": string,
    "originalUrl": string,
    "origin": string,
    "URL": string, /* Url object */
    "href": string,
    "host": string,
    "hostname": string,
    "headers": Js.Dict.t(string),
    [@bs.meth] "accepts": array(string) => unknownContent,
    [@bs.meth] "acceptsCharsets": array(string) => unknownContent,
    [@bs.meth] "acceptsEncodings": array(string) => unknownContent,
    [@bs.meth] "acceptsLanguages": array(string) => unknownContent,
    [@bs.meth] "is": array(string) => string,
    [@bs.meth] "get": string => string,
    [@bs.meth] "inspect": unit => Js.Dict.t(string),
    [@bs.meth] "toJSON": unit => Js.Json.t,
    "websocket": 'ws
  };

  type next = unit => Js.Promise.t(unit);
  type middleware('a, 'b) = (ctx('a, 'b), next) => Js.Promise.t(unit);

  [@bs.module] [@bs.new] external make : unit => t('a) = "koa";
  [@bs.get] external getMethod_ : t('a) => string = "method";
  [@bs.set] external setMethod_ : t('a) => method_ => unit = "method";
  [@bs.get] external getType_ : t('a) => string = "type";

  let method = fun
    | "GET" => Get
    | "POST" => Post
    | "PUT" => Put
    | "DELETE" => Delete
    | "HEAD" => Head
    | "OPTIONS" => Options
    | "TRACE" => Trace
    | "CONNECT" => Connect
    | s => failwith ({j|Koa.Request.method_ Unexpected method: $s|j});


  [@bs.send] external callback : t('a) => t('a) = "callback";
  [@bs.send] external use : t('a) => middleware('a, 'b) => 'c = "use";
  [@bs.send] external listen_ :
    t('a) =>
    int =>
    string =>
    (Js.Null_undefined.t(Js.Exn.t) => unit) =>
    unit = "listen";

  let listen = (~port=3000, ~hostname="localhost", ~callback=(_) => (), app) =>
    listen_(app, port, hostname, callback);
  let getMethod = ctx => getMethod_(ctx) |> method;
  let setMethod = (ctx, m) => setMethod_(ctx, m);
  let getType = ctx => getType_(ctx);
};
