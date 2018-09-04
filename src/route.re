open Koa;

module Route = {
  type t;
  type options = ref(list(Js.t({. name: string })));

  [@bs.module] external route : t = "koa-route";
  [@bs.send] external all: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "all";
  [@bs.send] external get: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "get";
  [@bs.send] external post: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "post";
  [@bs.send] external put: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "put";
  [@bs.send] external head: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "head";
  [@bs.send] external del: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "del";
  [@bs.send] external delete: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "delete";
  [@bs.send] external options: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "options";
  [@bs.send] external trace: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "trace";
  [@bs.send] external copy: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "copy";
  [@bs.send] external lock: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "lock";
  [@bs.send] external mkcol: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "mkcol";
  [@bs.send] external move: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "move";
  [@bs.send] external purge: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "purge";
  [@bs.send] external propfind: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "propfind";
  [@bs.send] external proppatch: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "proppatch";
  [@bs.send] external unlock: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "unlock";
  [@bs.send] external report: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "report";
  [@bs.send] external mkactivity: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "mkactivity";
  [@bs.send] external checkout: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "checkout";
  [@bs.send] external merge: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "merge";
  [@bs.send] external mSearch: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "m-search";
  [@bs.send] external notify: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "notify";
  [@bs.send] external subscribe: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "subscribe";
  [@bs.send] external unsubscribe: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "unsubscribe";
  [@bs.send] external patch: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "patch";
  [@bs.send] external search: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "search";
  [@bs.send] external connect: (t, string, App.middleware('a), ~opts: options=?) => App.middleware('a) = "connect";
};