package main;

import HopeUI "HopeUI/lib/core"

func main(){
	hui := HopeUI.New();
	hui.Init(800, 600, "Hellooo", hui.NewColor(255, 255, 255, 255), func (){
		hui.Label("Heyooo", 300, 300, 25, hui.NewColor(15, 15, 15, 255))
	})
}