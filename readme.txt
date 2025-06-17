

[OnPaint()와 OnEraseBkgnd() 처리 수정]
- CSCThemeDlg::OnPaint()에서 타이틀바를 그려줬으나 이 함수를 사용하면
  derived class의 OnPaint()에서 그림을 그려도 표시되지 않는다.
  일단 CSCThemeDlg::OnPaint()가 하던 일을 CSCThemeDlg::OnErageBkgnd()에서 하니
  derived class의 OnPaint()에서도 잘 그려지고 deactive 될 때 맨 위에 나타나는 흰색 띠를 없애기 위해
  derived class의 OnActivate()에서 timer를 사용하여 Invalidate() 했으나
  CSCThemeDlg::OnActivate()에서 Invalidate()을 호출하여 처리함.

[TitleBar 관련 검토 사항]
1. 항상 타이틀바가 표시되는 스타일

2. 전체 화면에서는 타이틀바가 표시되지 않고 마우스를 가져가야만 표시되는 스타일

- 위 두가지 모두 만족하기 위해서는 WS_CAPTION을 동적으로 표시하거나 감춰야 한다.
  그래야만 다른 child들이 타이탈바 유무에 따라 위치가 자동 조정된다.

* 우선 이 클래스를 사용하는 프로그램들이 많으므로 수정 작업은 신중해야 한다. 잠시 보류한다.