package HopeUI

// Helper contains helpful functions
type Helper struct{}

// Function is used as type func
type Function func()

// Color type, RGBA (32bit)
type Color struct {
	R uint8
	G uint8
	B uint8
	A uint8
}

// NewColor used to generate a color object
func (h *Helper) RGBA(R uint8, G uint8, B uint8, A uint8) Color {
	return Color{R: R, G: G, B: B, A: A}
}
